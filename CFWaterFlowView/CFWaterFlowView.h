//
//  CFWaterFlowView.h
//  CFWaterFlowView
//
//  Created by 周凌宇 on 15/11/30.
//  Copyright © 2015年 周凌宇. All rights reserved.
//  瀑布流UI控件

#import <UIKit/UIKit.h>
#import "CFWaterFlowViewCell.h"

#pragma mark - ========================枚举定义========================
typedef enum {
    CFWaterFlowViewMarginTypeTop,
    CFWaterFlowViewMarginTypeBottom,
    CFWaterFlowViewMarginTypeLeft,
    CFWaterFlowViewMarginTypeRight,
    // 列间距
    CFWaterFlowViewMarginTypeColumn,
    // 上下相邻cell间距
    CFWaterFlowViewMarginTypeRow
} CFWaterFlowViewMarginType;

#pragma mark - ========================数据源代理定义========================
@class CFWaterFlowView;
@protocol CFWaterFlowViewDataSource <NSObject>

@required
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

@optional
/**
 *  一共多少列，如果数据源没有设置，默认为2列
 *
 *  @param waterFlowView CFWaterFlowView对象
 *
 *  @return 瀑布流列数
 */
- (NSUInteger)numberOfColumnsInWaterFlowView:(CFWaterFlowView *)waterFlowView;

@end

#pragma mark - ========================代理定义=======================
@protocol CFWaterFlowViewDelegate <UIScrollViewDelegate>

@optional
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


@end


#pragma mark - ========================类定义=======================
@interface CFWaterFlowView : UIScrollView

/**
 *  数据源对象
 */
@property (nonatomic, weak) id<CFWaterFlowViewDataSource> dataSource;
/**
 *   代理对象
 */
@property (nonatomic, weak) id<CFWaterFlowViewDelegate> delegate;

/**
 *  刷新数据
 *  调用该方法会重新向数据源和代理发送请求。获取数据
 */
- (void)reloadData;

/**
 *  根据ID查找可循环利用的cell
 *
 *  @return 可循环利用的cell
 */
- (CFWaterFlowViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;

@end
