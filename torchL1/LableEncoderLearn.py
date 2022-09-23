
from sklearn.preprocessing  import OneHotEncoder
enc = OneHotEncoder()


data = enc.fit([[0, 0, 3], [1, 1, 0], [0, 2, 1], [1, 0, 2]])  # 注意：第1、2、3列分别有2、3、4个可能的取值
data2 = enc.transform([[0, 1, 3]]).toarray() #要对[0,1,3]进行编码
print(data2)