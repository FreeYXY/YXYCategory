//
//  UIBarButtonItem+CustomButtonItem.h
//  Weibo
//
//  Created by ios_ysj on 14/11/24.
//  Copyright (c) 2014年 ___XuHuiMing___. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (CustomButtonItem)

/**
 *  快速创建一个显示图片的item
 */
+ (UIBarButtonItem *)itemWithIcon:(NSString *)icon highlightIcon:(NSString *)highlightIcon target:(id)target action:(SEL)action;

+ (UIBarButtonItem *)itemWithTitle:(NSString *)title target:(id)target action:(SEL)action;

+ (UIBarButtonItem *)itemWithButton:(NSString *)icon highlightIcon:(NSString *)highlightIcon  title:(NSString *)title target:(id)target action:(SEL)action;
@end
