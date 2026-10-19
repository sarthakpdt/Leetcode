class Solution(object):
    def smallestSufficientTeam(self, req_skills, people):
        s_map={s: i for i, s in enumerate(req_skills)}
        dp={0: []}
        for i, p in enumerate(people):
            p_mask=0
            for s in p:
                p_mask|=1<<s_map[s]
            if not p_mask:
                continue
            for mask, team in list(dp.items()):
                n_mask=mask|p_mask
                if n_mask not in dp or len(dp[n_mask])>len(team)+1:
                    dp[n_mask]=team+[i]
        return dp[(1<<len(req_skills))-1]