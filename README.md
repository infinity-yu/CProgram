# git command
```c
git init    //初始化git
git config --global user.name "username"
git config --global user.email "username@gmail.com"

```
    
> 在GitHub上创建用户并创建一个仓库, 然后将仓库地址记录下来

![image](https://user-images.githubusercontent.com/87750069/127427679-12d9ea11-3f89-4c20-b55f-34265cd17fb8.png)

## 配置ssh密钥
```
ssh-keygen -t rsa -C "username@gmail.com"
// 生成的密钥一般默认保存在家目录下的.ssh文件夹中--------> ~/.ssh/id_rsa.pub
// 将pub文件中密钥添加

```

![image](https://user-images.githubusercontent.com/87750069/127428153-8d3d528e-89ad-4f88-b5de-8ffa472cd113.png)


# 给远程库起个别名
```
git remote add origin git@github.com:infinity-yu/linuxGit.git
// 可以通过git remote -v 查看
```
![image](https://user-images.githubusercontent.com/87750069/127428805-ab61246f-1051-48ef-849f-16a83ba0db4b.png)

# 克隆
```
git clone git@github.com:infinity-yu/linuxGit.git
//将远程仓库克隆到本地
```

# 从远程拉取
```
git pull origin master
```
- 拉取出错解决
```
git pull origin master --allow-unrelated-histories

```

# 添加到暂存区
```
git add filename
git commit -m "filename"    // -m 提交时输入提交信息
```


# 向远程推送
```
git push origin master
```




