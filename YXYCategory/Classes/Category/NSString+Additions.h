//
//  NSString+Additions.h
//  Addtions
//
//  Created by Hilen on 12/20/13.
//  Copyright (c) 2013 Yunyouhulian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <UIKit/UIKit.h>

@interface NSString (Additions)
@property (nonatomic, readonly) NSString *md5Hash;
@property (nonatomic, readonly) NSString *mdPhoneNo;// 手机号掩码处理
@property (nonatomic, readonly) NSString *mdName;// 姓名掩码处理
@property (nonatomic, readonly) NSString *mdBankcardNo;// 银行卡号掩码处理
@property (nonatomic, readonly) NSString *clearThumbnail;

- (NSString*)removeFloatAllZero;// 数字字符串 去除小数位的无用零

- (NSString *)MD5;
+ (NSString *)GetUUID; //获取唯一id
- (NSComparisonResult)versionStringCompare:(NSString *)other;
- (BOOL)isWhitespaceAndNewlines;
- (BOOL)isEmptyOrWhitespace;
- (BOOL)isEmail;
- (BOOL)isIncludeSpecialCharact;//是否包含特殊字符v3.0.2
- (BOOL)isLegalPrice;
- (BOOL)isNumber;
- (BOOL)isLegalName;
- (BOOL)isOnlyContainNumberOrLatter;
- (unichar)intToHex:(int)n;
- (BOOL)isCharSafe:(unichar)ch;
- (BOOL)containString:(NSString *)string;
- (NSString *)removeSpace;
- (NSString *)replaceSpaceWithUnderline;
- (NSString *)replaceDotWithUnderline;
+ (NSString *)replaceStringsFromDictionary:(NSDictionary *)dict stringName:(NSString *)name;
- (NSString *)encodeString;
- (NSString *)trimmedWhitespaceString;
- (NSString *)trimmedWhitespaceAndNewlineString;
// 日期格式转换
-(NSString *)dateFromStringWithOriginalFormat:(NSString*)originalFormat targetFormat:(NSString *)targetFormat;
// 字符串限定十个 多出部分...
-(NSString *)formatStringLimit;
// 数字字符串按每四位切割中间填充空格 
+ (NSString *)cutStringByRule:(NSString *)oldString;

/**
 *  在每n位插入指定字符串
 *
 *  @param aString  插入字符串
 *  @param indexs   间隔位数
 *
 *  @return 结果字符串
 */
- (NSString *)insertString:(NSString *)aString forEachIndexs:(NSUInteger)indexs;

+ (NSDate *)dateFromString:(NSString *)string;
+ (NSString *)convertDictionaryToJSON:(NSDictionary *)jsonObject;

- (NSDictionary *)parseURLParams;
- (NSDictionary *)toDictionary;
- (NSString *)getValueStringFromUrlForParam:(NSString *)param;
- (NSDate *)date;

- (NSString *)StringFromTimestamp;
- (NSString *)StringFromUTS;
- (NSString *)shortDateStringFromUTS;
- (BOOL)isPureFloat;
- (CGFloat)heightOfString:(NSString *)text textFontSize:(float)size widthSize:(float)width; //计算文字高度

/**
 *  计算文字高度 根据字体 宽度
 *
 *  @param text
 *  @param font
 *  @param width
 *
 *  @return
 */

//- (CGFloat)stringHeight:(NSString *)text textFontSize:(UIFont *)font widthSize:(float)width; //计算文字高度
- (CGFloat)stringHeightFontSize:(UIFont *)font widthSize:(float)width;
//- (CGFloat)widthOfString:(NSString *)string withFont:(UIFont *)font;
- (CGFloat)widthOfStringFont:(UIFont *)font;

- (NSMutableAttributedString *)getAttributedBySpace:(int)space;
- (NSString *)replace:(NSString *)source to:(NSString *)str;
+ (NSString *)getMacAddress;
- (BOOL)isContainStr:(NSString *)str;
//获取label数字尺寸
- (CGSize)getSizeWithFont:(UIFont *)font Size:(CGSize)size LineSpace:(int)space;
- (NSString *)trim;
- (NSString *)toMoney;// 金额格式转换
- (NSInteger)getNumberByString;// 获取字符串中的数字

+(NSString *) jsonStringWithDictionary:(NSDictionary *)dictionary;
+(NSString *) jsonStringWithArray:(NSArray *)array;
+(NSString *) jsonStringWithString:(NSString *) string;
+(NSString *) jsonStringWithObject:(id) object;

#pragma mark - 正则相关
- (BOOL)isValidateRealName;
- (BOOL)isValidateByRegex:(NSString *)regex;
//手机号分服务商
- (BOOL)isMobileNumberClassification;

// 校验身份证号只能为字母和数字 yes 符合  NO 不符合
-(BOOL)isValidateIDNo;

// 校验18位身份证号是否正确
- (BOOL)vertifyIdentityValid;

//  0-9纯数字
-(BOOL)isValidateNum;
/**
 限制输入emoji表情  直接过滤掉
 */
- (NSString *)disable_emoji;


/**
 除去特殊字符并限制字数的textFiled
 */
- (void)filterInputTextFieldMaskSpecialCharacter:(UITextField *)textField maxNumber:(NSInteger)maxNumber;

/**
 textFiled限制字数
 */
- (void)filterInputTextField:(UITextField *)textField maxNumber:(NSInteger)maxNumber;

/**
 除去特殊字符并限制字数的TextView
 */
- (void)filterInputTextViewMaskSpecialCharacter:(UITextView *)textView maxNumber:(NSInteger)maxNumber;

/**
 textView限制字数
 */
- (void)filterInputTextView:(UITextView *)textView maxNumber:(NSInteger)maxNumber;
/**
 根据正则过滤字符为纯汉字
 */
- (NSString *)filterCharactorToHanWord;

//利用正则表达式验证
-(BOOL)isValidateEmail;

@end
