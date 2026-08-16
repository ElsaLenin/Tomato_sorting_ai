import cv2
import numpy as np
import tensorflow as tf
import os

# Load model
model = tf.keras.models.load_model("tomato_model.keras")

# Class names (important: same order as training)
class_names = ['ripe', 'unripe']

img_size = 150

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    img = cv2.resize(frame, (img_size, img_size))
    img = np.expand_dims(img, axis=0)
    img = img / 255.0

    predictions = model.predict(img)
    print(predictions)
    predicted_class = class_names[np.argmax(predictions)]


    cv2.putText(frame, predicted_class.upper(),
                (20, 50),
                cv2.FONT_HERSHEY_SIMPLEX,
                1,
                (0, 255, 0),
                2)

    cv2.imshow("Tomato Prediction", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
