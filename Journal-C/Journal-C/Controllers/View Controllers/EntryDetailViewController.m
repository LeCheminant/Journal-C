//
//  EntryDetailViewController.m
//  Journal-C
//
//  Created by Jacob LeCheminant on 1/27/20.
//  Copyright © 2020 Jacob LeCheminant. All rights reserved.
//

#import "EntryDetailViewController.h"
#import "EntryController.h"

@interface EntryDetailViewController () <UITextFieldDelegate>

@end

@implementation EntryDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
}

- (void)setEntryLanding:(Entry *)entryLanding {
    _entryLanding = entryLanding;
    [self updateViews];
}
- (IBAction)clearButtonTapped:(id)sender {
    self.entryTitleTextField.text = @" ";
    self.bodyTextView.text = @" ";
}
- (IBAction)saveButtonTapped:(id)sender {
    if (self.entryLanding) {
        self.entryLanding.title = self.entryTitleTextField.text;
        self.entryLanding.bodyText = self.bodyTextView.text;
        self.entryLanding.timestamp = [NSDate date];
    } else {
        Entry *entry = [[[Entry alloc] initWithTimestamp:[NSDate date] title:self.entryTitleTextField.text bodyText:self.bodyTextView.text]];
        
        ] 
    }

- (void)updateViews {
    if (!self.entryLanding) return;
    self.entryTitleTextField.text = self.entryLanding.title;
    self.bodyTextView.text = [self.entryLanding.bodyText;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
                              
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
[textField resignFirstResponder];
return YES;
    }
                              
@end
