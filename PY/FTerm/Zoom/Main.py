import ctypes
import time
from AutoLog import AutoLogger
from Lessons import lessons
import win32gui
import win32con

def main():

    print_title()
    logger = AutoLogger(lessons)
    logger.log(99)
    # time.sleep(5)
    # close_window('Zoom')


def print_title():

    title = r'''   _         _          __                             
  /_\  _   _| |_ ___   / /  ___   __ _  __ _  ___ _ __ 
 //_\\| | | | __/ _ \ / /  / _ \ / _` |/ _` |/ _ \ '__|
/  _  \ |_| | || (_) / /__| (_) | (_| | (_| |  __/ |   
\_/ \_/\__,_|\__\___/\____/\___/ \__, |\__, |\___|_|   v0.1
                                 |___/ |___/           by: Gacrucis'''
    
    print(title)
    print()


def close_window(name):

    # while not win32gui.FindWindow(None, name):
    #     time.sleep(.5)

    handle = win32gui.FindWindow(None, name) 
    win32gui.PostMessage(handle,win32con.WM_CLOSE,0,0)

if __name__ == "__main__":
    main()

