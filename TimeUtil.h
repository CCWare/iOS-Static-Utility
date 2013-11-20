//The MIT License (MIT)
//
//Copyright (c) 2013 CCWare
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of
//this software and associated documentation files (the "Software"), to deal in
//the Software without restriction, including without limitation the rights to
//use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//the Software, and to permit persons to whom the Software is furnished to do so,
//subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  TimeUtil.h
//  iOS Static Utility
//
//  Created by Michael Tsai on 2011/10/06.

#import <Foundation/Foundation.h>

@interface TimeUtil : NSObject
+ (NSDate *)today;
+ (NSDate *)tomorrow;
+ (NSDate *)yesterday;
+ (NSDate *)dateFromToday: (int)days;
+ (NSDate *)dateFromString: (NSString *)string withFormat: (NSString *)format;
+ (NSDate *)dateOfYear: (int)yy month:(int)mm day:(int)dd;
+ (NSDate *)nextDayOfDate: (NSDate *)date;
+ (NSDate *)dateFromDate: (NSDate *)date inDays:(int)days;
+ (NSDate *)timeInDate: (NSDate *)date hour:(int)hr minute:(int)min second:(int)sec;
+ (int)yearOfDate: (NSDate *)date;
+ (int)monthOfDate: (NSDate *)date;
+ (int)dayOfDate: (NSDate *)date;
+ (NSString *)dateToString:(NSDate *)date inFormat:(NSString *)format;
+ (NSString *)dateToStringInCurrentLocale:(NSDate *)date;
+ (NSString *)dateToStringInCurrentLocale:(NSDate *)date dateStyle:(NSDateFormatterStyle)style;
+ (NSString *)stringFromHour:(int)hh minute:(int)mm;
+ (NSString *)timeToRelatedDescriptionFromNow:(NSDate *)date limitedRange:(int)days;

+ (int)daysBetweenDate:(NSDate *)date1 andDate:(NSDate *)date2;
+ (int)monthBetweenDate:(NSDate *)date1 andDate:(NSDate *)date2;

+ (NSDate *)thisWeekOfDate:(NSDate *)date;
+ (NSDate *)lastWeekOfDate:(NSDate *)date;
+ (NSDate *)nextWeekOfDate:(NSDate *)date;
+ (NSDate *)thisMonthOfDate:(NSDate *)date;
+ (NSDate *)lastMonthOfDate:(NSDate *)date;
+ (NSDate *)nextMonthOfDate:(NSDate *)date;
+ (NSDate *)thisYearOfDate:(NSDate *)date;
+ (NSDate *)nextYearOfDate:(NSDate *)date;

+ (BOOL)isExpired:(NSDate *)date;
+ (BOOL)isNearExpired:(NSDate *)expireDate nearExpiredDays:(int)day;
@end
