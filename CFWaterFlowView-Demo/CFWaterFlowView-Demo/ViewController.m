//
//  ViewController.m
//  CFWaterFlowView-Demo
//
//  Created by 周凌宇 on 15/11/30.
//  Copyright © 2015年 周凌宇. All rights reserved.
//

#import "ViewController.h"
#import "CFWaterFlowView.h"
#import "CFWaterFlowViewCell.h"

@interface ViewController () <CFWaterFlowViewDataSource, CFWaterFlowViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    CFWaterFlowView *waterFlowView = [[CFWaterFlowView alloc] init];
    waterFlowView.frame = self.view.bounds;
    waterFlowView.dataSource = self;
    waterFlowView.delegate = self;
    [self.view addSubview:waterFlowView];
}

#pragma mark - =======================CFWaterFlowView数据源=======================
- (NSUInteger)numberOfCellsInWaterFlowView:(CFWaterFlowView *)waterFlowView {
    return 100;
}

- (NSUInteger)numberOfColumnsInWaterFlowView:(CFWaterFlowView *)waterFlowView {
    return 3;
}

- (CFWaterFlowViewCell *)waterFlowView:(CFWaterFlowView *)waterFlowView cellAtIndex:(NSUInteger)index {
    CFWaterFlowViewCell *cell = [waterFlowView dequeueReusableCellWithIdentifier:@"reuseID"];
    
    if (cell == nil) {
        cell = [[CFWaterFlowViewCell alloc] init];
        cell.identifier = @"reuseID";
        cell.backgroundColor = [self randomColor];
        UILabel *label = [[UILabel alloc] init];
        label.tag = 101;
        label.frame = CGRectMake(20, 20, 30, 30);
        
        [cell addSubview:label];
    }
    
    UILabel *label = (UILabel *)[cell viewWithTag:101];
    label.text = [NSString stringWithFormat:@"%ld",index];
    
    return cell;
}

#pragma mark - =======================CFWaterFlowView代理=======================
- (CGFloat)waterFlowView:(CFWaterFlowView *)waterFlowView heightAtIndex:(NSUInteger)index {
    // [500,150)
    return (arc4random() % 101) + 100;;
    
}

- (CGFloat)waterFlowView:(CFWaterFlowView *)waterFlowView marginForType:(CFWaterFlowViewMarginType)type {
    switch (type) {
        case CFWaterFlowViewMarginTypeTop:
        case CFWaterFlowViewMarginTypeBottom:
        case CFWaterFlowViewMarginTypeLeft:
        case CFWaterFlowViewMarginTypeRight:
            return 12;
            break;
        default:
            return 5;
            break;
    }
}


#pragma mark - =======================Other=======================
- (void)waterFlowView:(CFWaterFlowView *)waterFlowView didSelectCellAtIndex:(NSUInteger)index {
    NSLog(@"点击cell，位置：%ld", index);
}

- (UIColor *)colorWithR:(NSUInteger)r G:(NSUInteger)g B:(NSUInteger)b {
    return [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1];
}

- (UIColor *)randomColor {
    return [self colorWithR:arc4random_uniform(255) G:arc4random_uniform(255) B:arc4random_uniform(255)];
}

@end
