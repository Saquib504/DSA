def minAddToMakeValid( s: str) -> int:
    opens = addons = 0

    for ch in s:
        if ch == '(':
            opens += 1
        else:
            if opens > 0:
                opens -= 1
            else:
                addons += 1
    return addons + opens


if __name__ == '__main__':
    s = input("Enter the String s : ")
    print(f"Minimum Add to Make Parenthesis Valid : {minAddToMakeValid(s)}")