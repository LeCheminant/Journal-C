//
//  Entry.m
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import "Entry.h"

@implementation Entry

- (instancetype)initWithTimestamp:(NSDate *)timestamp title:(NSString *)title bodyText:(NSString *)bodyText
{
    self = [super init];
    if (self) {
        _timestamp = timestamp;
        _title = title;
        _bodyText = bodyText;
    }
    
    return self;
}

@end
