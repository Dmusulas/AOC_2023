from pathlib import Path
import re as re

def read_and_parse(file: Path, **kwargs)-> dict[str, int]:
    ret = {}
    part1 = 0
    part2 = 0
    with open(file, "r") as f:
        for i, line in enumerate(f):
            i += 1
            ret[i] = parse(line)
            if (compare(ret[i], **kwargs)):
                part1 += i
            part2 += ret[i]["red"] * ret[i]["blue"] * ret[i]["green"]
    print(part1)
    print(part2)
    return ret

def parse(line: str):
    values = {}
    values["red"] = max(list(map(int, re.findall(r"(\d+) red", line))))
    values["blue"] = max(list(map(int, re.findall(r"(\d+) blue", line))))
    values["green"] = max(list(map(int, re.findall(r"(\d+) green", line))))
    return values

def compare(d: dict, red: int, green: int, blue: int) -> bool:
    return (d["green"] <= green and
            d["blue"] <= blue and
            d["red"] <= red)

def main():
    read_and_parse(Path("input.txt"), red=12, green = 13, blue=14)

if __name__ == "__main__":
    main()
