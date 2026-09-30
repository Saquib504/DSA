def maxDepthAfterSplit(seq: str) -> list[int]:
    ans = []
    cnt = 0

    for ch in seq:
        if ch == '(':
            cnt += 1
            ans.append(cnt % 2)
        else:
            ans.append(cnt % 2)
            cnt -= 1

    return ans


if __name__ == "__main__":
    seq = input("Enter the sequence: ")
    ans = maxDepthAfterSplit(seq)

    for x in ans:
        print(x, end = " ")

    print()