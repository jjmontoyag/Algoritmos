#https://www.quantopian.com/posts/a-couple-of-algo-ideas-from-a-newbie







# Do nothing unless the date has changed  
if todays_date == context.date:  
    return  
# Set the new date  
context.date = todays_date

cash = context.portfolio.cash  

# Load historical data for the stocks  
prices = history(18, '1d', 'open_price')  

# Use pandas dataframe.apply to get the last RSI value  
# for for each stock in our basket  
rsi = prices.apply(talib.RSI, timeperiod=14).iloc[-1]  

# Loop through our list of stocks  
for stock in context.stocks:  
    current_position = context.portfolio.positions[stock].amount  

    # RSI is above 70 and we own shares, time to sell  
    if rsi[stock] > context.HIGH_RSI and current_position > 0:  
        order_target(stock, 0)  
        log.info('{0}: RSI is at {1}, selling {2} shares'.format(  
            stock.symbol, rsi[stock], current_position  
        ))  

    # RSI is below 30 and we don't have any shares, time to buy  
    elif rsi[stock] < context.LOW_RSI and current_position == 0:  
        # Use floor division to get a whole number of shares  
        target_shares = cash // data[stock].price  
        order_target(stock, target_shares)  
        log.info('{0}: RSI is at {1}, buying {2} shares.'.format(  
            stock.symbol, rsi[stock], target_shares  
        ))

# record the current RSI values of each stock  
record(nflx_rsi=rsi[symbol('NFLX')],  
       amzn_rsi=rsi[symbol('AMZN')],  
       bwld_rsi=rsi[symbol('bwld')],  
       goog_rsi=rsi[symbol('goog')],)  
       
       
       
       
       
       
       
