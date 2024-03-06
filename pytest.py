import sys

sys.path.append("./out/lib")
import pyprint

def main():
    a=pyprint.add_fn(11, 13)
    print("add ret = ", a)
    pyprint.printf_color()

    for i in range(0, 1001, 10):
        print(f"{'*' * 46}")
        print(f"*{' '*12}Run Counts: --{i:^4}--{' '*12}*")
        print(f"{'*' * 46}")


if __name__ == '__main__':
    main()