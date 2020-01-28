//
//  EntryController.h
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Entry.h"

NS_ASSUME_NONNULL_BEGIN

@interface EntryController : NSObject

- (void)saveToPersistentStore {
    NSMutableArray *entriesToSave = [NSMutableArray<NSDictionary *> new];
    for (ZWWEntry *entry in self.entries) {
        [entriesToSave addObject:[entry dictionaryCopy]];
    }
    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:entriesToSave
                                                       options:kNilOptions
                                                         error:&error];
    if (error) {
        NSLog(@"Unable to convert entries to JSON: %@", error);
        return;
    }
    NSURL *url = [ZWWEntryController persistentStoreFileURL];
    [jsonData writeToURL:url atomically:YES];
}
- (void)loadFromPersistentStore {
    NSURL *url = [ZWWEntryController persistentStoreFileURL];
    NSError *error;
    NSData *data = [NSData dataWithContentsOfURL:url options:kNilOptions error:&error];
    if (error) {
        NSLog(@"Error loading JSON data from file: %@", error);
        return;
    }
    NSArray *rawEntries = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    if (error) {
        NSLog(@"Error converting JSON data to NSObject: %@", error);
        return;
    }
    NSMutableArray *newEntries = [NSMutableArray new];
    for (NSDictionary *entryDict in rawEntries) {
        ZWWEntry *entry = [[ZWWEntry alloc] initWithDictionary:entryDict];
        if (entry) {
            [newEntries addObject:entry];
        }
    }
    self.entries = newEntries;
}
+ (NSURL *)persistentStoreFileURL {
    NSArray<NSURL *> *urls = [[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory
                                                                    inDomains:NSUserDomainMask];
    return [urls[0] URLByAppendingPathComponent:@"journal.json"];
}







@property (nonatomic, strong) NSArray *entries;

- (void)addEntry:(Entry *)entry;
- (void)removeEntry:(Entry *)entry;

+ (EntryController *)sharedInstance;

@end

NS_ASSUME_NONNULL_END
