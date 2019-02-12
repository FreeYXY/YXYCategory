//
//  UIImage+Addition.h
//  DoubanAlbum
//
//  Created by Tonny on 12-12-13.
//  Copyright (c) 2012年 SlowsLab. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Additions)

@property (nonatomic, strong) NSMutableDictionary *gps;
- (BOOL)hasAlpha;
// 创建导航栏底部线
+(UIImage*)convertNavBarLineViewToImage;//

//压缩或拉伸图片方法
- (UIImage*)imageWithScaledToSize:(CGSize)newSize;
//设置图片的透明度
- (UIImage *)imageWithAlpha;

- (UIImage *)transparentBorderImage:(NSUInteger)borderSize;
- (UIImage *)transformWidth:(CGFloat)width
                    height:(CGFloat)height;

//从项目里读取图片资源
+ (UIImage *)imageWithFileName:(NSString *)imageName;
+ (UIImage *)imageWithFileName:(NSString *)imageName type:(NSString *)type;

//可以用来拉伸图片
- (UIImage *)resizableImageWithSize:(CGSize)size;

//创建一个纯色图片
+ (UIImage *)imageWithColor:(UIColor *)color;

//在图片上写字
+ (UIImage *)drawText:(NSString*)text inImage:(UIImage*)image atPoint:(CGPoint)point fontSize:(CGFloat )size;

//把小图加到大图上
+ (UIImage *)addSmallImage:(UIImage *)image1 toBigImage:(UIImage *)image2 rectSmall:(CGRect)rectSmall rectBig:(CGRect)rectBig;

//创建圆角图片
- (UIImage *)roundedCornerImage:(NSInteger)cornerSize borderSize:(NSInteger)borderSize;

// 高斯模糊效果 毛玻璃
-(UIImage *)coreBlurImageWithBlurNumber:(CGFloat)blur;
// 高斯模糊效果
-(UIImage *)boxblurImageWithBlurNumber:(CGFloat)blur;

//创建一个纯色的圆角图片
+ (UIImage *)imageWithColor:(UIColor *)color
               cornerRadius:(CGFloat)cornerRadius;

+ (UIImage *)buttonImageWithColor:(UIColor *)color
                     cornerRadius:(CGFloat)cornerRadius
                      shadowColor:(UIColor *)shadowColor
                     shadowInsets:(UIEdgeInsets)shadowInsets;

+ (UIImage *)circularImageWithColor:(UIColor *)color
                               size:(CGSize)size;

- (UIImage *)imageWithMinimumSize:(CGSize)size;

+ (UIImage *)stepperPlusImageWithColor:(UIColor *)color;
+ (UIImage *)stepperMinusImageWithColor:(UIColor *)color;

+ (UIImage *)backButtonImageWithColor:(UIColor *)color
                           barMetrics:(UIBarMetrics) metrics
                         cornerRadius:(CGFloat)cornerRadius;

+ (UIImage *)captureScreen;
+ (UIImage *)imageNamedByTabbar:(NSString *)imageName;
//图片等比缩放
+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;

+ (UIImage *)resizeImage:(UIImage *)originImage
                FromSise:(CGSize)originSize
             ToSizeWidth:(float)width;

+ (UIImage *)resizeImage:(UIImage *)originImage
                FromSise:(CGSize)originSize
                  ToSize:(CGSize)finialSize;
//修复图片旋转问题
+ (UIImage *)scaleAndRotateImage:(UIImage *)image;
- (UIImage *)accelerateBlurWithImage:(UIImage *)image;
- (UIImage *)fixOrientation:(UIImage *)srcImg;
- (UIImage *)imageByApplyingAlpha:(CGFloat) alpha;
//正方形的
- (UIImage *)squareImageFromImage:(UIImage *)image scaledToSize:(CGFloat)newSize;
@end
