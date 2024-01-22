# -*- coding: utf-8 -*-
"""Copy of Welcome To Colaboratory

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1VSFXM47aPr1VJk_idgbAbkLnKjn4Vnxu
"""

from google.colab import drive
drive.mount('/content/gdrive')

cd /content/gdrive/MyDrive/fyp_module

ROOT_DIR = '/content/gdrive/MyDrive/fyp_module'

!pip install ultralytics
import os

from ultralytics import YOLO

# Load a model
model = YOLO("yolov8n.yaml") # build a new model from scratch
# Use the model
results = model.train (data=os.path.join (ROOT_DIR, "google_colab_config.yaml"), epochs=50) # train the model

!yolo train model=yolov8n.pt data=google_colab_config.yaml epochs=50 imgsz=640

import locale
locale.getpreferredencoding = lambda: "UTF-8"

!scp -r /content/gdrive/MyDrive/fyp_module/runs '/content/gdrive/MyDrive/fyp_module'
!yolo predict model='/content/gdrive/MyDrive/fyp_module/runs/detect/train4/weights/best.pt' source='/content/gdrive/MyDrive/fyp_module/data/val/images'