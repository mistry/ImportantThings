import string
def main():

    n = GetWeekNumber()/7


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
def GetWeekNumber():
    import datetime
    desiredWeekday = 6 #Sunday
    today = datetime.date.today()
    FoY = today.replace(month =1, day =1)#FoY = First of Year
    FirstSunday = FoY.replace(day = (desiredWeekday + 1 - FoY.weekday()))#The 1 is there to make sure the day isn't set to 0
    deltatime = today - FirstSunday
    return (deltatime.days)
if __name__ == '__main__':
    main()

