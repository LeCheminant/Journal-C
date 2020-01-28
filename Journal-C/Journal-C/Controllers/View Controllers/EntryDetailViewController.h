//
//  EntryDetailViewController.h
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Entry.h"

NS_ASSUME_NONNULL_BEGIN

@interface EntryDetailViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITextField *entryTitleTextField;
@property (strong, nonatomic) IBOutlet UITextView *bodyTextView;

// @property (strong, nonatomic) Entry *entry;
@property (nonatomic) Entry *entryLanding;

@end

NS_ASSUME_NONNULL_END
