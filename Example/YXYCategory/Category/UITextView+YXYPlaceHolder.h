//
//  UITextView+YXYPlaceHolder.h
//  AnTrader
//
//  Created by YXY on 2018/12/17.
//  Copyright © 2018 Techwis. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITextView (YXYPlaceHolder)
/**
 *  UITextView+placeholder
 */
@property (nonatomic, copy) NSString *yxy_placeHolder;
/**
 *  IQKeyboardManager等第三方框架会读取placeholder属性并创建UIToolbar展示
 */
@property (nonatomic, copy) NSString *placeholder;
/**
 *  placeHolder颜色
 */
@property (nonatomic, strong) UIColor *yxy_placeHolderColor;

/**
 *  placeHolder字号
 */
@property (nonatomic, strong) UIFont *yxy_placeHolderFont;


/** 限制字数*/
@property (nonatomic, assign) NSInteger yxy_limitCount;
/** lab的右边距(默认10)*/
@property (nonatomic, assign) CGFloat yxy_labMargin;
/** lab的高度(默认20)*/
@property (nonatomic, assign) CGFloat yxy_labHeight;
/** 统计限制字数Label*/
@property (nonatomic, readonly) UILabel *yxy_inputLimitLabel;
@end

NS_ASSUME_NONNULL_END
