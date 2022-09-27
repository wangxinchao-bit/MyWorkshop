import os
import numpy as np
from PIL import Image
 
def gen_datasets(bg_path, minions_path, img_path, label_path):
    count = 0
    with open(label_path, "w") as f:
        for filename in os.listdir(bg_path):                             #遍历文件列表              操作背景图
 
            bg_img = Image.open("{0}/{1}".format(bg_path, filename))
            bg_img = bg_img.convert("RGB")                                #转换通道
            bg_img = bg_img.resize((224, 224))                            #统一大小
 
            bg_img.save("{}/{}.png".format(img_path, count))              #保存变化后的图像
 
            f.write("{}.png {} {} {} {} {}\n".format(count, 0, 0, 0, 0, 0))   #负样本
            count += 1
            name = np.random.randint(1, 21)
            minions_img = Image.open("{}/{}.png".format(minions_path, name))
            new_w = np.random.randint(50, 100)
            new_h = np.random.randint(50, 100)
            resize_img = minions_img.resize((new_w, new_h))               #随机缩放
            rot_img = resize_img.rotate(np.random.randint(-180,180))      #随机旋转
            paste_x1 = np.random.randint(0, 224-new_w)
            paste_y1 = np.random.randint(0, 224-new_h)
            r, g, b, a = rot_img.split()                                   #划分出透明通道
            bg_img.paste(rot_img, (paste_x1, paste_y1), mask=a)           #在透明通道上粘贴         #合并小黄人与背景图
            paste_x2 = paste_x1+new_w
            paste_y2 = paste_y1+new_h
            bg_img.save("{}/{}.png".format(img_path, count))               #保存处理后的图片
            f.write("{}.png {} {} {} {} {}\n".format(
            count, 1, paste_x1, paste_y1, paste_x2, paste_y2))
            count += 1
            print(count)
            if count > 1000:
                print(count)
                break
 
if __name__ == '__main__':
    bg_img = r"D:\Desktop\Learnn\Minions\back_ground_dir"
    minions_img = r"D:\Desktop\Learnn\Minions\minions_dir"
    root_dir = r"D:\Desktop\Learnn\Minions"
 
    # train_img = r"./train_img"
    train_img = os.path.join(root_dir, "train_img")
    validate_img = os.path.join(root_dir, "validate_img")
    test_img = os.path.join(root_dir, "test_img")
 
    for i in (train_img,validate_img, test_img):
        if not os.path.isdir(i):
            os.makedirs(train_img)
 
    train_label = r"./train_label.txt"
    validate_label = r"./validate_label.txt"
    test_label = r"./test_label.txt"
 
    gen_datasets(bg_img, minions_img, train_img, train_label)
    gen_datasets(bg_img, minions_img, validate_img, validate_label)
    gen_datasets(bg_img, minions_img, test_img, test_label)