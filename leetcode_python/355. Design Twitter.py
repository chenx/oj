class User:
    def __init__(self, userId):
        self.userId = userId
        self.followers = set() # [userId]
        self.myTweets : list[list[int]] = [] # [[tweetId, followerId, tweetUniqueId]]
        self.newsFeed : list[list[int]] = [] # [[tweetId, followerId, tweetUniqueId]]
        # postTweet: add to self's newsFeed, and each followee's newsFeed.
    
    def mergeNewsFeed(self, feed2):
        result = []
        feed1 = self.newsFeed
        n1, n2 = len(feed1), len(feed2)
        i, j = 0, 0
        while i < n1 and j < n2:
            if feed1[i][2] < feed2[j][2]:
                result.append(feed1[i])
                i += 1
            else:
                result.append(feed2[j])
                j += 1
        while i < n1:
            result.append(feed1[i])
            i += 1
        while j < n2:
            result.append(feed2[j])
            j += 1
        self.newsFeed = result

    def removeNewsFeed(self, feed2):
        feedCountToRemove = list(map(lambda x : x[2], feed2))
        result = []
        for feed in self.newsFeed:
            if feed[2] not in feedCountToRemove:
                result.append(feed)
        self.newsFeed = result


class Twitter:

    def __init__(self):
        self.users : dict[int, User] = {}
        self.tweetUniqueId = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.addDefaultUser(userId)
        self.tweetUniqueId += 1

        tweet = [tweetId, userId, self.tweetUniqueId]
        self.users[userId].myTweets.append(tweet.copy())

        self.users[userId].newsFeed.append(tweet.copy())
        for id in self.users[userId].followers:
            self.users[id].newsFeed.append(tweet.copy())
        

    def getNewsFeed(self, userId: int) -> List[int]:
        self.addDefaultUser(userId)
        result = self.users[userId].newsFeed[-10:][:][::-1]
        return list(map(lambda x : x[0], result))
        

    def follow(self, followerId: int, followeeId: int) -> None:
        self.addDefaultUser(followerId)
        self.addDefaultUser(followeeId)

        if followerId in self.users[followeeId].followers:
            return # already following, don't follow again.

        self.users[followeeId].followers.add(followerId)
        self.users[followerId].mergeNewsFeed(self.users[followeeId].myTweets)


    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.addDefaultUser(followerId)
        self.addDefaultUser(followeeId)

        if followerId not in self.users[followeeId].followers:
            return # not following, can't unfollow

        self.users[followeeId].followers.remove(followerId)

        self.users[followerId].removeNewsFeed(self.users[followeeId].myTweets)
        # This also works.
        # for feed in reversed(self.users[followerId].newsFeed):
        #     if feed[1] == followeeId:
        #         self.users[followerId].newsFeed.remove(feed)
        
    def addDefaultUser(self, userId):
        if userId not in self.users:
            self.users[userId] = User(userId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)


/**
355. Design Twitter
Solved
Medium
Topics
conpanies iconCompanies

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, 
and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

    Twitter() Initializes your twitter object.
    void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
        Each call to this function will be made with a unique tweetId.
    List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. 
        Each item in the news feed must be posted by users who the user followed or by the user themself. 
        Tweets must be ordered from most recent to least recent.
    void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
    void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 */
