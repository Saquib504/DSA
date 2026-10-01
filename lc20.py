def isValid(s: str) -> bool:
    stk = []
    mapping = {')' : '(', ']' : '[', '}' : '{'}

    for char in s:
        if char in mapping.values():
            stk.append(char)
        elif char in mapping:
            if not stk or stk[-1] != mapping[char]:
                return False
            stk.pop()
        else:
            return False
    return len(stk) == 0

if __name__ == '__main__':
    s = input("Enter string s : ")

    if isValid(s) == True:
        print("The string is valid!!")
    else:
        print("The string is not valid!")