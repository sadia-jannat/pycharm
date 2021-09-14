import re

regex = '^[a-z0-9]+[\._]?[a-z0-9]+[@]\w+[.]\w{2,3}$'


def check(email):
    if (re.search(regex, email)):
        print("Valid Email")
    else:
        print("Invalid Email")


if __name__ == '__main__':
    email = "sadiatonni1995@gmail.com"
    check(email)

    email = "tajrian.@_jahangmail.com"
    check(email)

    email = "rupajahan@gmail.com"
    check(email)

    email = "nafisa.das@mcnsolutions.net"
    check(email)

    email = "cmc@c-medical.com"
    check(email)
