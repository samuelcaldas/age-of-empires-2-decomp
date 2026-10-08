"""Exception types raised by the agy delegation tools."""


class AgyDelegationError(Exception):
    """Base class for every error raised by the delegation tools."""


class ProfileError(AgyDelegationError):
    """A task profile is missing, malformed, or names an unknown option."""


class InputError(AgyDelegationError):
    """Task inputs are missing, unknown, or point outside the allowed area."""


class AgyUnavailableError(AgyDelegationError):
    """The agy executable is not on PATH or is not executable."""
