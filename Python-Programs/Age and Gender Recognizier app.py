import cv2
import numpy as np
import time

# Load files
face_model = "opencv_face_detector_uint8.pb"
face_proto = "opencv_face_detector.pbtxt" 
gender_model = "gender_net.caffemodel"
gender_proto = "gender_deploy.prototxt"
age_model = "age_net.caffemodel"
age_proto = "age_deploy.prototxt"
  
cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)
face_net = cv2.dnn.readNet(face_model, face_proto)
gender_net = cv2.dnn.readNet(gender_model, gender_proto)
age_net = cv2.dnn.readNet(age_model, age_proto)

model_mean_values = (78.4263377603, 87.7689143744, 114.895847746)
age_list = ['(0-2)', '(4-6)', '(8-12)', '(15-20)', '(25-32)', '(38-43)', '(48-53)', '(60-100)']
gender_list = ['Male', 'Female']
padding = 20 
c_time, p_time = 0, 0

def face_bbox(img, face_net):
    bbox = []
    h, w, c = img.shape
    blob = cv2.dnn.blobFromImage(img, 1, (227, 227), [104, 117, 123], swapRB=False)
    face_net.setInput(blob)
    detection = face_net.forward()
    for i in range(detection.shape[2]):
        confidence = detection[0, 0, i, 2]
        if confidence > 0.7:
            x = int(detection[0, 0, i, 3] * w)
            y = int(detection[0, 0, i, 4] * h)
            x1 = int(detection[0, 0, i, 5] * w)
            y1 = int(detection[0, 0, i, 6] * h)
            bbox.append([x, y, x1, y1])
            cv2.rectangle(img, (x, y), (x1, y1), (255, 0, 0), 2)
            
    return img, bbox


while True:
    success, img = cap.read()
    img, bboxs = face_bbox(img, face_net)
    for bbox in bboxs:
        face = img[max(0,bbox[1]-padding):min(bbox[3]+padding,img.shape[0]-1),max(0,bbox[0]-padding):min(bbox[2]+padding, img.shape[1]-1)]
        blob = cv2.dnn.blobFromImage(face, 1, (227, 227), model_mean_values, swapRB=False)
        gender_net.setInput(blob)
        gender_pred = gender_net.forward()
        gender = gender_list[gender_pred[0].argmax()]
        age_net.setInput(blob)
        age_pred = age_net.forward()                                                                                                    
        age = age_list[age_pred[0].argmax()]
        label = "{},{}".format(gender, age)
        cv2.putText(img, label, (bbox[0], bbox[1]), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255, 0), 2)

    c_time = time.time()
    fps = 1 / (c_time - p_time)
    p_time = c_time
    cv2.putText(img, f"FPS: {int(fps)}", (30, 70), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255, 0), 2)

    cv2.imshow("Video", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break