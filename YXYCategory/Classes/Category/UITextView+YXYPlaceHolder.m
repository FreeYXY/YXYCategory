//
//  UITextView+YXYPlaceHolder.m
//  AnTrader
//
//  Created by YXY on 2018/12/17.
//  Copyright © 2018 Techwis. All rights reserved.
//

#import "UITextView+YXYPlaceHolder.h"
#import <objc/runtime.h>

//static const void *yxy_placeHolderKey;
static NSString *const yxy_placeHolderKey = @"yxy_placeHolderKey";
static NSString *const limitCountKey = @"limitCountKey";
static NSString *const labMarginKey = @"labMarginKey";
static NSString *const labHeightKey = @"labHeightKey";

@interface UITextView ()
@property (nonatomic, readonly) UILabel *yxy_placeHolderLabel;
@end

@implementation UITextView (YXYPlaceHolder)
+(void)load{
    [super load];
    method_exchangeImplementations(class_getInstanceMethod(self.class, NSSelectorFromString(@"layoutSubviews")),
                                   class_getInstanceMethod(self.class, @selector(yxyPlaceHolder_swizzling_layoutSubviews)));
    method_exchangeImplementations(class_getInstanceMethod(self.class, NSSelectorFromString(@"dealloc")),
                                   class_getInstanceMethod(self.class, @selector(yxyPlaceHolder_swizzled_dealloc)));
    method_exchangeImplementations(class_getInstanceMethod(self.class, NSSelectorFromString(@"setText:")),
                                   class_getInstanceMethod(self.class, @selector(yxyPlaceHolder_swizzled_setText:)));
}
#pragma mark - swizzled
- (void)yxyPlaceHolder_swizzled_dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    @try {
        [self removeObserver:self forKeyPath:@"layer.borderWidth"];
        [self removeObserver:self forKeyPath:@"text"];
    } @catch (NSException *exception) {
        
    } @finally {
        
    }
    [self yxyPlaceHolder_swizzled_dealloc];
}
- (void)yxyPlaceHolder_swizzling_layoutSubviews {
    if (self.yxy_placeHolder) {
        UIEdgeInsets textContainerInset = self.textContainerInset;
        CGFloat lineFragmentPadding = self.textContainer.lineFragmentPadding;
        CGFloat x = lineFragmentPadding + textContainerInset.left + self.layer.borderWidth;
        CGFloat y = textContainerInset.top + self.layer.borderWidth;
        CGFloat width = CGRectGetWidth(self.bounds) - x - textContainerInset.right - 2*self.layer.borderWidth;
        CGFloat height = [self.yxy_placeHolderLabel sizeThatFits:CGSizeMake(width, 0)].height;
        self.yxy_placeHolderLabel.frame = CGRectMake(x, y, width, height);
    }
    [self yxyPlaceHolder_swizzling_layoutSubviews];
    // 字数限制
    if (self.yxy_limitCount) {
        UIEdgeInsets textContainerInset = self.textContainerInset;
        textContainerInset.bottom = self.yxy_labHeight;
        self.contentInset = textContainerInset;
        CGFloat x = CGRectGetMinX(self.frame)+self.layer.borderWidth;
        CGFloat y = CGRectGetMaxY(self.frame)-self.contentInset.bottom-self.layer.borderWidth;
        CGFloat width = CGRectGetWidth(self.bounds)-self.layer.borderWidth*2;
        CGFloat height = self.yxy_labHeight;
        self.yxy_inputLimitLabel.frame = CGRectMake(x, y, width, height);
        if ([self.superview.subviews containsObject:self.yxy_inputLimitLabel]) {
            return;
        }
        [self.superview insertSubview:self.yxy_inputLimitLabel aboveSubview:self];
    }
}
- (void)yxyPlaceHolder_swizzled_setText:(NSString *)text{
    [self yxyPlaceHolder_swizzled_setText:text];
    if (self.yxy_placeHolder) {
        [self updatePlaceHolder];
    }
}
#pragma mark - associated
-(NSString *)yxy_placeHolder{
    return objc_getAssociatedObject(self, &yxy_placeHolderKey);
}

-(void)setYxy_placeHolder:(NSString *)yxy_placeHolder{
    objc_setAssociatedObject(self, &yxy_placeHolderKey, yxy_placeHolder, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self updatePlaceHolder];
}
-(UIColor *)yxy_placeHolderColor{
    return self.yxy_placeHolderLabel.textColor;
}
-(void)setYxy_placeHolderColor:(UIColor *)yxy_placeHolderColor{
    self.yxy_placeHolderLabel.textColor = yxy_placeHolderColor;
}

-(UIFont *)yxy_placeHolderFont{
    return self.yxy_placeHolderLabel.font;
}
-(void)setYxy_placeHolderFont:(UIFont *)yxy_placeHolderFont{
    self.yxy_placeHolderLabel.font = yxy_placeHolderFont;
}

-(NSString *)placeholder{
    return self.yxy_placeHolder;
}
-(void)setPlaceholder:(NSString *)placeholder{
    self.yxy_placeHolder = placeholder;
}
#pragma mark - update
- (void)updatePlaceHolder{
    if (self.text.length) {
        [self.yxy_placeHolderLabel removeFromSuperview];
        return;
    }
    self.yxy_placeHolderLabel.font = self.font?self.font:self.cacutDefaultFont;
    self.yxy_placeHolderLabel.textAlignment = self.textAlignment;
    self.yxy_placeHolderLabel.text = self.yxy_placeHolder;
    [self insertSubview:self.yxy_placeHolderLabel atIndex:0];
}
#pragma mark - lazzing
-(UILabel *)yxy_placeHolderLabel{
    UILabel *placeHolderLab = objc_getAssociatedObject(self, @selector(yxy_placeHolderLabel));
    if (!placeHolderLab) {
        placeHolderLab = [[UILabel alloc] init];
        placeHolderLab.numberOfLines = 0;
        placeHolderLab.textColor = [UIColor lightGrayColor];
        objc_setAssociatedObject(self, @selector(yxy_placeHolderLabel), placeHolderLab, OBJC_ASSOCIATION_RETAIN);
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updatePlaceHolder) name:UITextViewTextDidChangeNotification object:self];
    }
    return placeHolderLab;
}
- (UIFont *)cacutDefaultFont{
    static UIFont *font = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        UITextView *textview = [[UITextView alloc] init];
        textview.text = @" ";
        font = textview.font;
    });
    return font;
}

#pragma mark 字数限制
#pragma mark - associated
-(NSInteger)yxy_limitCount{
    return [objc_getAssociatedObject(self, &limitCountKey) integerValue];
}
- (void)setYxy_limitCount:(NSInteger)yxy_limitCount{
    objc_setAssociatedObject(self, &limitCountKey, @(yxy_limitCount), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self updateLimitCount];
}
-(CGFloat)yxy_labMargin{
    return [objc_getAssociatedObject(self, &labMarginKey) floatValue];
}
-(void)setYxy_labMargin:(CGFloat)yxy_labMargin{
    objc_setAssociatedObject(self, &labMarginKey, @(yxy_labMargin), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self updateLimitCount];
}
-(CGFloat)yxy_labHeight{
    return [objc_getAssociatedObject(self, &labHeightKey) floatValue];
}
-(void)setYxy_labHeight:(CGFloat)yxy_labHeight{
    objc_setAssociatedObject(self, &labHeightKey, @(yxy_labHeight), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self updateLimitCount];
}
#pragma mark -config
- (void)configTextView{
    self.yxy_labHeight = 20;
    self.yxy_labMargin = 10;
}
#pragma mark - update
- (void)updateLimitCount{
    if (self.text.length > self.yxy_limitCount) {
        UITextRange *markedRange = [self markedTextRange];
        if (markedRange) {
            return;
        }
        NSRange range = [self.text rangeOfComposedCharacterSequenceAtIndex:self.yxy_limitCount];
        self.text = [self.text substringToIndex:range.location];
    }
    NSString *showText = [NSString stringWithFormat:@"%lu/%ld",(unsigned long)self.text.length,(long)self.yxy_limitCount];
    self.yxy_inputLimitLabel.text = showText;
    NSMutableAttributedString *attrString = [[NSMutableAttributedString
                                              alloc] initWithString:showText];
    NSUInteger length = [showText length];
    NSMutableParagraphStyle *
    style = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
    style.tailIndent = -self.yxy_labMargin; //设置与尾部的距离
    style.alignment = NSTextAlignmentRight;//靠右显示
    [attrString addAttribute:NSParagraphStyleAttributeName value:style
                       range:NSMakeRange(0, length)];
    self.yxy_inputLimitLabel.attributedText = attrString;
}
-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context{
    if ([keyPath isEqualToString:@"layer.borderWidth"]||
        [keyPath isEqualToString:@"text"]) {
        [self updateLimitCount];
    }
}
#pragma mark - lazzing
-(UILabel *)yxy_inputLimitLabel{
    UILabel *label = objc_getAssociatedObject(self, @selector(yxy_inputLimitLabel));
    if (!label) {
        label = [[UILabel alloc] init];
        label.backgroundColor = self.backgroundColor;
        label.textColor = [UIColor lightGrayColor];
        label.textAlignment = NSTextAlignmentRight;
        objc_setAssociatedObject(self, @selector(yxy_inputLimitLabel), label, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(updateLimitCount)
                                                     name:UITextViewTextDidChangeNotification
                                                   object:self];
        [self addObserver:self forKeyPath:@"layer.borderWidth" options:NSKeyValueObservingOptionNew context:nil];
        [self addObserver:self forKeyPath:@"text" options:NSKeyValueObservingOptionNew context:nil];
        [self configTextView];
    }
    return label;
}



@end
