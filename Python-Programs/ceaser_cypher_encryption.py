alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet = list(alphabet)
n = input("Enter the sentence to be encrypted ").lower().split(" ")
s = int(input("Enter the number to be shifted by "))
shifted_alphabet = alphabet[s:] + alphabet[:s]
coded = [shifted_alphabet[alphabet.index(j)] for i in n for j in i]
print("".join(coded))
