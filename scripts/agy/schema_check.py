"""Minimal JSON Schema validator for the subset used by agy profiles.

Supports `type`, `enum`, `properties`, `required`, `additionalProperties`
(false only), and `items`. Anything else in a schema is ignored, so profile
schemas must stay inside this subset.
"""

from typing import Any

from errors import AgyDelegationError


class SchemaViolation(AgyDelegationError):
    """A value does not match the schema. The message names the JSON path."""


TYPE_CHECKS = {
    "object": lambda value: isinstance(value, dict),
    "array": lambda value: isinstance(value, list),
    "string": lambda value: isinstance(value, str),
    "integer": lambda value: isinstance(value, int) and not isinstance(value, bool),
    "number": lambda value: isinstance(value, (int, float)) and not isinstance(value, bool),
    "boolean": lambda value: isinstance(value, bool),
}


def validate(value: Any, schema: dict, path: str = "$") -> None:
    """Raise SchemaViolation if `value` does not satisfy `schema`."""
    _check_type(value, schema, path)
    _check_enum(value, schema, path)
    if isinstance(value, dict):
        _check_object(value, schema, path)
    if isinstance(value, list) and "items" in schema:
        _check_items(value, schema["items"], path)


def _check_type(value: Any, schema: dict, path: str) -> None:
    expected = schema.get("type")
    if expected is None:
        return
    if not TYPE_CHECKS[expected](value):
        raise SchemaViolation(f"{path}: expected {expected}, got {type(value).__name__}")


def _check_enum(value: Any, schema: dict, path: str) -> None:
    allowed = schema.get("enum")
    if allowed is not None and value not in allowed:
        raise SchemaViolation(f"{path}: {value!r} is not one of {allowed}")


def _check_object(value: dict, schema: dict, path: str) -> None:
    for key in schema.get("required", []):
        if key not in value:
            raise SchemaViolation(f"{path}: missing required property '{key}'")
    properties = schema.get("properties", {})
    if schema.get("additionalProperties") is False:
        _check_no_extra(value, properties, path)
    for key, subschema in properties.items():
        if key in value:
            validate(value[key], subschema, f"{path}.{key}")


def _check_no_extra(value: dict, properties: dict, path: str) -> None:
    extra = sorted(set(value) - set(properties))
    if extra:
        raise SchemaViolation(f"{path}: unexpected properties {extra}")


def _check_items(value: list, item_schema: dict, path: str) -> None:
    for index, item in enumerate(value):
        validate(item, item_schema, f"{path}[{index}]")
