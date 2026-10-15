import subprocess

def main():
    obj_out = subprocess.check_output([
        "build/mips_binutils/mips-linux-gnu-objdump", "-dr", "build/SLES-50282/src/trade_action_market_eval_planner.o"
    ]).decode("utf-8")
    obj_lines = [l for l in obj_out.splitlines() if ":\t" in l]

    with open("build/SLES-50282/asm/trade_action_market_eval_planner.s") as f:
        asm_lines = [l.strip() for l in f if "/* 4F" in l]

    print(f"Compiled instructions: {len(obj_lines)}, Target instructions: {len(asm_lines)}")

    for i in range(min(len(obj_lines), len(asm_lines))):
        ol = obj_lines[i]
        al = asm_lines[i]
        o_parts = ol.split(":\t")[1]
        a_parts = al.split("*/")[1].strip()

        # print first 150 lines or any mismatches
        o_code = " ".join(o_parts.split()[1:])
        print(f"{i*4:03X} | {o_parts:45} | {a_parts}")

if __name__ == "__main__":
    main()
