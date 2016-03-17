//
//  NSString+NSString_hash.h
//  RewardTest
//
//  Created by yukatou on 2016/03/16.
//  Copyright © 2016年 yukatou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (NSString_hash)

+ (NSString *)sha256:(NSString *)text;
+ (NSString *)sha1:(NSString *)text;
@end
