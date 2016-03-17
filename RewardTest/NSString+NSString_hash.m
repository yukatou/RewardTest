//
//  NSString+NSString_hash.m
//  RewardTest
//
//  Created by yukatou on 2016/03/16.
//  Copyright © 2016年 yukatou. All rights reserved.
//

#import "NSString+NSString_hash.h"
#import <CommonCrypto/CommonHMAC.h>

@implementation NSString (NSString_hash)



+ (NSString *)sha256:(NSString *)text
{
    const char *s=[text cStringUsingEncoding:NSASCIIStringEncoding];
    NSData *keyData=[NSData dataWithBytes:s length:strlen(s)];
    
    uint8_t digest[CC_SHA256_DIGEST_LENGTH]={0};
    CC_SHA256(keyData.bytes, keyData.length, digest);
    NSData *out = [NSData dataWithBytes:digest length:CC_SHA256_DIGEST_LENGTH];
    NSString *hash=[out description];
    hash = [hash stringByReplacingOccurrencesOfString:@" " withString:@""];
    hash = [hash stringByReplacingOccurrencesOfString:@"<" withString:@""];
    hash = [hash stringByReplacingOccurrencesOfString:@">" withString:@""];
    return hash;
    
}

+ (NSString *)sha1:(NSString *)text
{
    NSData *cData = [text dataUsingEncoding:NSUTF8StringEncoding];
    uint8_t result[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1(cData.bytes, cData.length, result);
    NSMutableString *ret = [NSMutableString stringWithCapacity:CC_SHA1_DIGEST_LENGTH*2];
    for(int i = 0; i<CC_SHA1_DIGEST_LENGTH; i++)
    {
        [ret appendFormat:@"%02x",result[i]];
    }
    return ret;
}

@end