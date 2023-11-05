import argparse

def main():
    parser = argparse.ArgumentParser(description="My CLI Tool")
    parser.add_argument("--option", help="An optional argument")
    args = parser.parse_args()
    
    if args.option:
        print(f"Option value: {args.option}")
    else:
        print("No option specified")

if __name__ == "__main__":
    main()
