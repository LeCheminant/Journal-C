//
//  EntryController.m
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import "EntryController.h"

@interface EntryController()

@property (nonatomic, strong) NSMutableArray *internalEntries;

@end

@implementation EntryController

+ (EntryController *)sharedInstance
{
     static EntryController *sharedInstance = nil;
     static dispatch_once_t onceToken;
     dispatch_once(&onceToken, ^{
         sharedInstance = [EntryController new];
     });
     return sharedInstance;
    
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _internalEntries = [NSMutableArray array];
    }
    return self;
}

//MARK: - Methods
- (NSArray *)entries { return self.internalEntries; }

- (void)addEntry:(Entry *)entry {
    [self.internalEntries addObject:entry];
}

- (void)removeEntry:(Entry *)entry {
    [self.internalEntries removeObject:entry];
}


@end
