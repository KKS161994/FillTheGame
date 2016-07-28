//
//  ViewController.m
//  FillAndWin
//
//  Created by kartikey on 29/07/16.
//  Copyright © 2016 Teamie. All rights reserved.
//

#import "ViewController.h"
#import "FillAndWin-Swift.h"
@interface ViewController ()
{
 CSVParser *csv;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSString *path = [[NSBundle mainBundle]pathForResource:@"Dictionary" ofType:@"csv"];
    csv = [[CSVParser alloc]initWithContentsOfURL:path error:nil];
    //for(NSDictionary *dict in [[csv rows]count]){
    NSString *randomWord =[[[csv rows]objectAtIndex:[self getRandomNumberBetween:0 to:[[csv rows]count]]] valueForKey:@"word"];
    NSLog(@"Dict%@",randomWord);
    
    WikipediaHelper *wikiHelper = [[WikipediaHelper alloc] init];
    wikiHelper.apiUrl = @"http://en.wikipedia.org";
    wikiHelper.delegate = self;
    [wikiHelper fetchArticle:randomWord];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(int)getRandomNumberBetween:(int)from to:(int)to {
    
    return (int)from + arc4random() % (to-from+1);
}
- (void)dataLoaded:(NSString *)htmlPage withUrlMainImage:(NSString *)urlMainImage {
    NSLog(@"HTML Page: %@", htmlPage);
    NSLog(@"Main image url: %@", urlMainImage);}

@end
