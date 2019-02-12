//
//  NSString+DecimalsCalculation.h
//  
//
//  Created by YXY on 2017/11/13.
//  Copyright © 2017年 Techwis. All rights reserved.
//

// CalculationType

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger,CalculationType){
    CalculationAdding,
    CalculationSubtracting,
    CalculationMultiplying,
    CalculationDividing,
};

#import <Foundation/Foundation.h>
/**
 // Rounding policies :
 // Original
 //    value 1.2  1.21  1.25  1.35  1.27
 // Plain    1.2  1.2   1.3   1.4   1.3
 // Down     1.2  1.2   1.2   1.3   1.2
 // Up       1.2  1.3   1.3   1.4   1.3
 // Bankers  1.2  1.2   1.2   1.4   1.3
 
 typedef NS_ENUM(NSUInteger, NSRoundingMode) {
 NSRoundPlain,   // 四舍五入
 NSRoundDown,    // 向下取舍
 NSRoundUp,      // 向上入
 NSRoundBankers  // 同四舍五入。但是当需要进位的数字是5时根据前一位的奇偶性，奇数向上取值、偶数向下取值
 };
 */

@interface NSString (DecimalsCalculation)

// 加
/**
 加法计算，默认保留两位小数，默认采用四舍五入的方式处理计算结果,
 roundingModel决定四舍五入的方式，scale决定保留小数个数
 @param stringNumber 被加数
 @return 返回结果
 */
- (NSString *)yxy_stringByAdding:(NSString *)stringNumber;
- (NSString *)yxy_stringByAdding:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel;
- (NSString *)yxy_stringByAdding:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel scale:(NSInteger)scale;

// 减
/**
 减法计算，默认保留两位小数，默认采用四舍五入的方式处理计算结果
 roundingModel决定四舍五入的方式，scale决定保留小数个数
 @param stringNumber 减数
 @return 返回结果
 */
- (NSString *)yxy_stringBySubtracting:(NSString *)stringNumber;
- (NSString *)yxy_stringBySubtracting:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel;
- (NSString *)yxy_stringBySubtracting:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel scale:(NSInteger)scale;

// 乘
/**
 乘法计算，默认保留两位小数，默认采用四舍五入的方式处理计算结果
 roundingModel决定四舍五入的方式，scale决定保留小数个数
 @param stringNumber 减数
 @return 返回结果
 */
- (NSString *)yxy_stringByMultiplyingBy:(NSString *)stringNumber;
- (NSString *)yxy_stringByMultiplyingBy:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel;
- (NSString *)yxy_stringByMultiplyingBy:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel scale:(NSInteger)scale;

// 除

/**
 除法计算，默认保留两位小数，默认采用四舍五入的方式处理计算结果
 roundingModel决定四舍五入的方式，scale决定保留小数个数
 @param stringNumber 减数
 @return 返回结果
 */
- (NSString *)yxy_stringByDividingBy:(NSString *)stringNumber;
- (NSString *)yxy_stringByDividingBy:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel;
- (NSString *)yxy_stringByDividingBy:(NSString *)stringNumber withRoundingMode:(NSRoundingMode)roundingModel scale:(NSInteger)scale;

/**
 比较两个字符串大小
 @return 返回结果
 */
- (NSComparisonResult )yxy_comparey:(NSString *)stringNumber;

// 不四舍五入 如果为整数就没有小数位
- (NSString *)yxy_notRoundingAfterPoint:( NSInteger )position;
// 不四舍五入  如果计算结果为整数 保留小数位补零
- (NSString *)yxy_notRoundingTwoAfterPoint:( NSInteger )position;

/** 传入字符串类型数值做加减乘除操作  不需保留小数位精度。 返回一个字符串*/
-(NSString *)yxy_decimalNumberCalculationWithStringOne:(NSString *)stringOne type:(CalculationType)type;

// string 转 decimal
-(NSDecimalNumber *)yxy_decimalValue;
@end

