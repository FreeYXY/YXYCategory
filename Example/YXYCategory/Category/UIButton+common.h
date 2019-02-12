//
//  UIButton+common.h
//  xiaoanLoan
//
//  Created by YXY on 2017/6/6.
//  Copyright © 2017年 YXY. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, MKButtonEdgeInsetsStyle) {
    MKButtonEdgeInsetsStyleTop, // image在上，label在下
    MKButtonEdgeInsetsStyleLeft, // image在左，label在右
    MKButtonEdgeInsetsStyleBottom, // image在下，label在上
    MKButtonEdgeInsetsStyleRight // image在右，label在左
};

@interface UIButton (common)
//@property (nonatomic, assign) NSTimeInterval yxy_eventInterval;

/**
 *  设置button的titleLabel和imageView的布局样式，及间距
 *
 *  @param style titleLabel和imageView的布局样式
 *  @param space titleLabel和imageView的间距
 */
- (void)layoutButtonWithEdgeInsetsStyle:(MKButtonEdgeInsetsStyle)style
                        imageTitleSpace:(CGFloat)space;
// 设置按钮指定位置圆角
-(void)setupBtnCornerRadiusReact:(CGRect)react rectCorner:(UIRectCorner)rectCorner cornerRadii:(CGSize)cornerRadii;

@end
