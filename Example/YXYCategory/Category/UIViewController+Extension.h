//
//  UIViewController+Extension.h
//  GroupPurchase
//
//  Created by ios_ysj on 15/1/26.
//
//

#import <UIKit/UIKit.h>

@interface UIViewController (Extension)

/**
 * 左右边间隙以及缩小触摸范围
 */
- (void)setNavigationBarButtonLeftItem:(UIBarButtonItem *)item;
- (void)setNavigationBarButtonRightItem:(UIBarButtonItem *)item;
- (void)setNavigationBarButtonLeftItem:(UIBarButtonItem *)item animated:(BOOL)animated;
- (void)setNavigationBarButtonRightItem:(UIBarButtonItem *)item animated:(BOOL)animated;
@property (nonatomic, readonly) BOOL apl_hidesNavigationBarWhenPushed;
@end
