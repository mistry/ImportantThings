import string
def main():
    try:
        n = int(raw_input("Enter number 0-25 "))
    except ValueError:
        print "That number sucks"
    cipher_maps = GetMap(n)
    text = raw_input("Enter text to be translated ")
    text = string.lower(text)
    coded_text = DoTranslation(text,cipher_maps[0])
    decoded_text = DoTranslation(coded_text,cipher_maps[1])
    print coded_text
    print decoded_text
def DoTranslation(text, cipher):
    output_text=""
    for i in range(len(text)):
        if text[i] !=' ':
            output_text+=(cipher[text[i]])
        else:
            output_text+=' '
    return output_text
    
def GetMap(n):
    forward_map = dict.fromkeys(string.ascii_lowercase,0)
    backward_map = dict.fromkeys(string.ascii_lowercase,0)
    for i in range(0,26):
        forward_map[chr(97+i)] = chr(97+((i+n)%26))
        backward_map[chr(97+i)]= chr(97+((i-n)%26))
    return [forward_map,backward_map]
if __name__ == '__main__':
    main()
