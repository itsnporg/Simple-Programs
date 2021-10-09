import cv2
import pytesseract

img = cv2.imread("text.jpg") # Add the path of the image from where you want text.
pytesseract.pytesseract.tesseract_cmd = r'C:/Program Files/Tesseract-OCR/tesseract.exe' # Add the path of the tesseract


img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)


print(pytesseract.image_to_string(img_rgb))

cv2.imshow("Document", img)

cv2.waitKey(0)
