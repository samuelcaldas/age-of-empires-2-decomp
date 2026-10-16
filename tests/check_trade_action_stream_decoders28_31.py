"""Run the independent Ninja and raw-byte proof for decoders28-31."""

from trade_action_stream_decoders28_31_proof import prove_all, require_root


if __name__ == "__main__":
    require_root()
    prove_all()
