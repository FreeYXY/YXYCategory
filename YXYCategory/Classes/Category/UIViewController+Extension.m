//
//  UIViewController+Extension.m
//  GroupPurchase
//
//  Created by ios_ysj on 15/1/26.
//
//

#import "UIViewController+Extension.h"

@implementation UIViewController (Extension)


#pragma mark - 设置左右边的的间隔
- (void)setNavigationBarButtonLeftItem:(UIBarButtonItem *)item
{
    [self setNavigationBarButtonLeftItem:item animated:NO];
}
- (void)setNavigationBarButtonRightItem:(UIBarButtonItem *)item
{
    [self setNavigationBarButtonRightItem:item animated:NO];
}

- (void)setNavigationBarButtonLeftItem:(UIBarButtonItem *)leftItem animated:(BOOL)animated
{
    
    // 调整 leftBarButtonItem 在 iOS7 下面的位置
    if(([[[UIDevice currentDevice] systemVersion] floatValue]>=7.0?20:0)){
        UIBarButtonItem *negativeSpacer = [[UIBarButtonItem alloc]
                                           initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace
                                           target:nil action:nil];
        negativeSpacer.width = -10;
        self.navigationItem.leftBarButtonItems = @[negativeSpacer, leftItem];
    }else {
        self.navigationItem.leftBarButtonItem = leftItem;
    }
    
    
//    UIView *view = [[UIView alloc] init];
//    view.backgroundColor = [UIColor redColor];
//    UIBarButtonItem *marginItem = [[UIBarButtonItem alloc] initWithCustomView:view];
//    
//    float version = [[[UIDevice currentDevice] systemVersion] floatValue];
//    if ( version >= 7.0 && version<8.39)
//    {
//        UIBarButtonItem *negativeSeperator = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil];
//        negativeSeperator.width = -10;
//        
//        if (leftItem)
//        {
//            [self.navigationItem setLeftBarButtonItems:@[negativeSeperator, leftItem,marginItem]];
//        }
//        else
//        {
//            [self.navigationItem setLeftBarButtonItems:@[negativeSeperator]];
//        }
//        
//    }
//    else
//    {
//        [self.navigationItem setLeftBarButtonItems:@[leftItem] animated:animated];
//    }
//
}


- (void)setNavigationBarButtonRightItem:(UIBarButtonItem *)rightItem animated:(BOOL)animated
{
//    float version = [[[UIDevice currentDevice] systemVersion] floatValue];
//    if ( version >= 7.0 && version<8.39)
//    {
//        UIBarButtonItem *negativeSeperator = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil];
//        negativeSeperator.width = -10;
//        
//        if (rightItem)
//        {
//            [self.navigationItem setRightBarButtonItems:@[negativeSeperator, rightItem]];
//        }
//        else
//        {
//            [self.navigationItem setRightBarButtonItems:@[negativeSeperator]];
//        }
//        
//    }
//    else
//    {
        [self.navigationItem setRightBarButtonItems:@[rightItem] animated:animated];
//    }
}

- (BOOL)apl_hidesNavigationBarWhenPushed {
    return NO;
}
@end
