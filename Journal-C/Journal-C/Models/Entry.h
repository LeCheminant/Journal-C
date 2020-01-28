//
//  Entry.h
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Entry: NSObject

@property (nonatomic, copy) NSDate *timestamp;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *bodyText;

- (instancetype) initWithTimestamp:(NSDate *)timestamp
                             title:(NSString *)title
                          bodyText:(NSString *)bodyText;



@end

NS_ASSUME_NONNULL_END
