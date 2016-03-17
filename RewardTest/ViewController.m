//
//  ViewController.m
//  RewardTest
//
//  Created by yukatou on 2016/03/16.
//  Copyright © 2016年 yukatou. All rights reserved.
//

#import "ViewController.h"
#import "NSString+NSString_hash.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *adstirButton;
@property (nonatomic, strong) AdstirVideoReward *reward;
@property (nonatomic, assign) NSUInteger retry;
@property (nonatomic, strong) NSString *userId;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    self.userId = [[NSBundle mainBundle] objectForInfoDictionaryKey: @"UserID"];
    
    self.retry = 0;
    self.adstirButton.enabled = NO;
    self.adstirButton.alpha = 0.3;
    
    self.reward = [[AdstirVideoReward alloc]initWithMedia:@"MEDIA-58d52411" spot:7];
    self.reward.delegate = self;
    
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [self.reward load];
    });
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)tapCARewardButton:(id)sender {
    
    NSInteger ownerId = 1206;
    NSInteger mediaId = 6203;
    NSString *apikey = @"92455b5f47e4d540";
    NSString *userId = self.userId;
    NSString *crypt = [NSString sha1:[userId stringByAppendingString:apikey]];
    
    NSString *urlStr = [NSString stringWithFormat:@"https://car.mobadme.jp/spg/spnew/%ld/%ld/index.php?user_id=%@&crypt=%@&from_id=%@", (long)ownerId, (long)mediaId, userId, crypt, apikey];
    NSLog(@"%@", urlStr);
    
    NSURL *url = [NSURL URLWithString:urlStr];
    [[UIApplication sharedApplication] openURL:url];
}

- (IBAction)tapAppDriverButton:(id)sender {

    NSInteger siteId = 12074;
    NSString *identifier = self.userId;
    NSInteger mediaId = 2770;
    NSString *key = @"fb419f63e49834158d39a00a8daff5d3";
    NSString *str = [NSString stringWithFormat:@"%@;%ld;%@", identifier, (long)mediaId, key];
    NSString *digest = [NSString sha256:str];
    
    NSString *urlStr = [NSString stringWithFormat:@"http://appdriver.jp/3.1.%ldi?identifier=%@&media_id=%ld&digest=%@", (long)siteId, identifier, (long)mediaId, digest];
    NSLog(@"%@", urlStr);
    
    NSURL *url = [NSURL URLWithString:urlStr];
    [[UIApplication sharedApplication] openURL:url];
}

- (IBAction)tapAdstirButton:(id)sender {
    if ([self.reward canShow]) {
        [self.reward show];
    }
}

- (void)adstirVideoRewardDidLoad:(AdstirVideoReward *)videoReward
{
    NSLog(@"load");
    self.adstirButton.enabled = YES;
    self.adstirButton.alpha = 1.0;
}

- (void)adstirVideoRewardDidStart:(AdstirVideoReward *)videoReward
{
    NSLog(@"start");
}


- (void)adstirVideoRewardDidClose:(AdstirVideoReward *)videoReward
{
    NSLog(@"close");
}

- (void)adstirVideoRewardDidComplete:(AdstirVideoReward *)videoReward
{
    NSLog(@"complete");
}

-(void)adstirVideoRewardDidFinishPlayback:(AdstirVideoReward *)videoReward
{
    NSLog(@"playback");
}

-(void)adstirVideoRewardDidCancel:(AdstirVideoReward *)videoReward
{
    NSLog(@"cancel");
}

-(void)adstirVideoReward:(AdstirVideoReward *)videoReward didFailToLoadWithError:(NSError *)error
{
    NSLog(@"%@", [error debugDescription]);
    
    if (self.retry < 3) {
        self.retry++;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            [self.reward load];
        });
    }
    
}

- (void)adstirVideoReward:(AdstirVideoReward *)videoReward didFailToPlaybackWithError:(NSError *)error
{
    NSLog(@"%@", [error debugDescription]);
}

@end
