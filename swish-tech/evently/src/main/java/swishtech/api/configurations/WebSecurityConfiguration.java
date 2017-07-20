package swishtech.api.configurations;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.authentication.configurers.GlobalAuthenticationConfigurerAdapter;
import org.springframework.security.core.authority.AuthorityUtils;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import swishtech.api.repositories.RoleRepo;
import swishtech.api.repositories.UserRepo;

@Configuration
class WebSecurityConfiguration extends GlobalAuthenticationConfigurerAdapter
{

	@Autowired
	UserRepo userRepo;
	
	@Autowired
	RoleRepo roleRepo;

	@Override
	public void init(AuthenticationManagerBuilder auth) throws Exception
	{
		auth.userDetailsService(userDetailsService());
	}

	@Bean
	UserDetailsService userDetailsService()
	{
		return new UserDetailsService()
		{
			@Override
			public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException
			{
				swishtech.api.models.User user = userRepo.findByEmail(email);
				if(user != null)
				{
					return new User(user.getEmail(), user.getPassword(), true, true, true, true, AuthorityUtils.createAuthorityList(roleRepo.findOne(user.getRoleId()).getRole()));
				}
				else
				{
					throw new UsernameNotFoundException("could not find the user '"+ email + "'");
				}
			}
		};
	}
}