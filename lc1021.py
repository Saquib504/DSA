def removeOuterParentheses( s: str) -> str:
    cnt = 0
    result = ""

    for ch in s:
        if ch == '(' :
            if cnt > 0:
                result += '('
            cnt += 1
        else:
            cnt -= 1
            if cnt > 0:
                result += ')'

    return result

if __name__ == "__main__":
    s = input("Enter Stirng : ")
    print(f"String after removing parenthesis : {removeOuterParentheses(s)}")