//
//  WikipediaHelper.h
//  FillAndWin
//
//  Created by kartikey on 29/07/16.
//  Copyright © 2016 Teamie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"

/**
 *  Protocol is used to transport the result
 */
@protocol WikipediaHelperDelegate <NSObject>
- (void) dataLoaded:(NSString *)htmlPage withUrlMainImage:(NSString *) urlMainImage;
@end

@interface WikipediaHelper : NSObject {
    NSString *apiUrl;
    NSMutableArray *imageBlackList;
    NSString *fetchedArticle;
    id delegate;
}

/**
 *  Asynchronously fetches an wikipedia article HTML Code from the wikipedia api
 *
 *  @param name Name of the article which will be searched
 */
- (void) fetchArticle:(NSString *)name;

/**
 *  Format the HTML page, make sure all the links are correct
 *
 *  @param htmlSrc Unformatted HTML source
 *
 *  @return Formatted HTML source
 */
- (NSString *) formatHTMLPage:(NSString *)htmlSrc;

/**
 *  Find the main image of the article and return the url
 *
 *  @param Unformatted HTML source
 *
 *  @return URL to the main image of the article
 */
- (NSString *) getUrlOfMainImage:(NSString *)htmlSrc;

/**
 *  Checks if the returned image is on the blacklist.
 *
 *  @param imageURL URL which will be checked
 *
 *  @return If its a black list image or not
 */
- (BOOL) isOnBlackList:(NSString *)imageURL;

@property (nonatomic, retain) NSString *apiUrl;
@property (nonatomic, retain) NSMutableArray *imageBlackList;
@property (nonatomic, retain) NSString *fetchedArticle;
@property (nonatomic, retain) id delegate;

@end
