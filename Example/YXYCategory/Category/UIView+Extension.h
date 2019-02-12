//
//  UIView+Extension.h
//  farmlink
//
//  Created by 赵小嘎 on 15/11/9.
//  Copyright © 2015年 farmlink. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Masonry.h>

@interface UIView (Extension)

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;
@property (nonatomic, assign) CGFloat top;
@property (nonatomic, assign) CGFloat bottom;
@property (nonatomic, assign) CGFloat left;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGFloat tail;
@property (nonatomic, assign) CGFloat right;
@property (nonatomic, assign, readonly) CGFloat maxX;
@property (nonatomic, assign, readonly) CGFloat maxY;


- (NSString *)getNametag;
- (void)setNametag:(NSString *)theNametag;

-(UIView *)viewNamed:(NSString *)aName;

// 视图所在控制器
- (UIViewController *)viewController;
// view to image
-(UIImage*)imageFromView;

// 利用masonry 水平排列一组视图
- (void) distributeSpacingHorizontallyWith:(NSArray*)views;
// 利用masonry 垂直排列一组视图
- (void) distributeSpacingVerticallyWith:(NSArray*)views;
-(void)CornerRadiusRectCornerRect:(CGRect)rect rectCorner:(UIRectCorner)rectCorner cornerRadii:(CGSize)cornerRadii;

/**  设置圆角  */
- (void)rounded:(CGFloat)cornerRadius;

/**  设置圆角和边框  */
- (void)rounded:(CGFloat)cornerRadius width:(CGFloat)borderWidth color:(UIColor *)borderColor;

/**  设置边框  */
- (void)border:(CGFloat)borderWidth color:(UIColor *)borderColor;

/**   给哪几个角设置圆角  */
-(void)round:(CGFloat)cornerRadius RectCorners:(UIRectCorner)rectCorner;

/**  设置阴影  */
-(void)shadow:(UIColor *)shadowColor opacity:(CGFloat)opacity radius:(CGFloat)radius offset:(CGSize)offset;

+ (CGFloat)getLabelHeightByWidth:(CGFloat)width Title:(NSString *)title font:(UIFont *)font;

@end
