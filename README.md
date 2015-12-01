# Introduction
CFWaterFlowView是一个简单易用、支持自定义cell的瀑布流框架

你可以：

1. 自定义瀑布流的列数
2. 自定义cell的样式
3. 自定义内容的上下左右边距
4. 自定义每列之间的间距，上下cell之间的间距

![CFWaterFlowView展示](http://7xnrog.com1.z0.glb.clouddn.com/github_iOS-CFWaterFlowView-show-01.png-w375)

![CFWaterFlowView展示](http://7xnrog.com1.z0.glb.clouddn.com/github_iOS-CFWaterFlowView-show-02.jpg-w375)

# Future
1. 支持横竖屏切换的适应

# Install
## Normal
将CFWaterFlowView文件夹下所有文件拖入你的项目中

文件列表：

`CFWaterFlowView.h`

`CFWaterFlowView.m`

`CFWaterFlowViewCell.h`

`CFWaterFlowViewCell.m`

## CocoaPods
即将支持

# Usage
CFWaterFlowView是通过UIScrollView实现的。CFWaterFlowView使用方法非常类似于UITableView，你可以类比UITableView的使用。

你需要：

1. 遵守`CFWaterFlowViewDataSource`协议
2. 遵守`CFWaterFlowViewDelegate`协议
3. 实现相应的方法

## CFWaterFlowViewDataSource

必须实现的方法方法如下：
 
```

/**
 *  一共多少cell
 *
 *  @param waterFlowView CFWaterFlowView对象
 *
 *  @return cell总个数，NSUInteger保证正数
 */
- (NSUInteger)numberOfCellsInWaterFlowView:(CFWaterFlowView *)waterFlowView;
/**
 *  返回对应索引的cell
 *
 *  @param waterFlowView CFWaterFlowView对象
 *  @param index         索引
 *
 *  @return 对应索引的cell
 */
- (CFWaterFlowViewCell *)waterFlowView:(CFWaterFlowView *)waterFlowView cellAtIndex:(NSUInteger)index;

```

可选实现的方法方法如下：

```

/**
 *  一共多少列，如果数据源没有设置，默认为2列
 *
 *  @param waterFlowView CFWaterFlowView对象
 *
 *  @return 瀑布流列数
 */
- (NSUInteger)numberOfColumnsInWaterFlowView:(CFWaterFlowView *)waterFlowView;

```

## CFWaterFlowViewDelegate
可选实现的方法方法如下：

```

/**
 *  返回对应索引的cell的高度
 *
 *  @param waterFlowView CFWaterFlowView对象
 *  @param index         索引
 *
 *  @return 对应索引的cell的高度
 */
- (CGFloat)waterFlowView:(CFWaterFlowView *)waterFlowView heightAtIndex:(NSUInteger)index;
/**
 *  点击cell回调
 *
 *  @param waterFlowView CFWaterFlowView对象
 *  @param index         索引
 */
- (void)waterFlowView:(CFWaterFlowView *)waterFlowView didSelectCellAtIndex:(NSUInteger)index;
/**
 *  返回对应间距类型的间距
 *
 *  @param waterFlowView CFWaterFlowView对象
 *  @param type          间距类型
 *
 *  @return 对应间距类型的间距
 */
- (CGFloat)waterFlowView:(CFWaterFlowView *)waterFlowView marginForType:(CFWaterFlowViewMarginType)type;

```

# Custom Cell
你可以看到CFWaterFlowView和UITableView的使用方法极其类似。在自定义cell也同样

如果不需要自定义cell，你可以在你的控制器里这样写：

```

- (CFWaterFlowViewCell *)waterFlowView:(CFWaterFlowView *)waterFlowView cellAtIndex:(NSUInteger)index {
    CFWaterFlowViewCell *cell = [waterFlowView dequeueReusableCellWithIdentifier:@"ID"];
    
    if (cell == nil) {
        cell = [[CFWaterFlowViewCell alloc] init];
        cell.identifier = @"ID";
    }
    return cell;
}

```

如果需要自定义cell，你需要编写自己的cell类型，并使其继承于`CFWaterFlowViewCell`，再将你的控制器中代码改为：

```

- (CFWaterFlowViewCell *)waterFlowView:(CFWaterFlowView *)waterFlowView cellAtIndex:(NSUInteger)index {
    YourCell *cell = [waterFlowView dequeueReusableCellWithIdentifier:@"ID"];
    
    if (cell == nil) {
        cell = [[YourCell alloc] init];
        cell.identifier = @"ID";
    }
    return cell;
}

```

# Other
你可以参考Demo，在Demo中已经详细、简洁的告诉你如何使用CFWaterFlowView

希望你能喜欢CFWaterFlowView

# Feedback
如果有什么修改建议，可以发送邮件到coderfish@163.com，也欢迎到我的[博客](http://zhoulingyu.com)