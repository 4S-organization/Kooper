from picamera import PiCamera
import os
from datetime import datetime

OUTPUT_IMAGES = ('outputs/images', False)

def TakePicture(resolution=(1920, 1080)):

    with PiCamera as camera:
        camera.resolution = resolution
        camera.start_preview()

        # For wake up camera
        time.sleep(3)
        if os.path.exists(OUTPUT_IMAGES[0]) == False:
            try:
                MakeOutputDir(OUTPUT_IMAGES[0])
                OUTPUT_IMAGES[1] = True
            except:
                pass
        else:
            camera.capture(f'{OUTPUT_IMAGES}/picture_{datetime.now().strftime('%H.%M.%S')}')

    

def MakeOutputDir(name):
    os.mkdir(f'{name}')