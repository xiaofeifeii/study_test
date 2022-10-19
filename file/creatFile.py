
with open('./book.dat', 'wb+') as f:
    # for i in range(10):
    #     txt=str(i+1000)+"  python课本   50块钱\n"
    #     f.write(txt.encode())
    txt = f.read()
    print("txt:", txt.encode(encoding='utf-8'))
