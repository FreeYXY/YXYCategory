//
//  NSDataAddition.h
//  DoubanAlbum
//
//  modify from Three20 by Tonny on 6/5/11.
//  Copyright 2012 SlowsLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface NSData (Additions)

@property (nonatomic, readonly) NSString *md5Hash;

/**
 *  截取当前屏幕
 *
 *  @return NSData *
 */
+ (NSData *)dataWithScreenshotInPNGFormat;

- (NSString *)MD5;
@end
