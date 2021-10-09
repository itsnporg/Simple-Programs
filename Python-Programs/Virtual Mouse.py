from cvzone.HandTrackingModule import HandDetector
import cv2
import numpy as np 
import pyautogui
import cvzone

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)
hand_detector = HandDetector(maxHands=1)
cvw, cvh = 640, 480
sw, sh = pyautogui.size()
frame_cut = 0.2
smooth = 7
cx, cy, px, py = 0, 0, 0, 0
min_area, max_area = 5000, 11000
cap.set(3, cvw)
cap.set(4, cvh)


while True:
    success, img = cap.read()
    img = hand_detector.findHands(img, draw=True)
    lmlist, bboxs = hand_detector.findPosition(img, draw=True)
    
    if bboxs:
        bbox = bboxs['bbox']
        cv2.rectangle(img, (int(frame_cut * cvw), int(frame_cut * cvh)), (int(cvw - (frame_cut * cvw)), int(cvh - (frame_cut * cvh))), (255, 0, 0), 5)
        fingers = hand_detector.fingersUp()
        total_finger = fingers.count(1)
        index_finger = fingers[1]
        if index_finger == 1: 
            x, y = lmlist[8][0], lmlist[8][1]
            x, y = np.interp(x, (0 + frame_cut * cvw, cvw - frame_cut * cvw), (0, sw)), np.interp(y, (0 + frame_cut * cvh, cvh - frame_cut * cvh), (0, sh))
            cx = px + (x - px) / smooth
            cy = py + (y - py) / smooth
            try:
                pyautogui.moveTo(int(cx), int(cy))
            except:
                pass
            distance, img, info = hand_detector.findDistance(8, 12, img, draw=True)
            area = bbox[2] * bbox[3]
            if distance <= 20:
                pyautogui.click(int(cx), int(cy), button='left')
            px, py = cx, cy
            
    cv2.imshow("Video", img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break