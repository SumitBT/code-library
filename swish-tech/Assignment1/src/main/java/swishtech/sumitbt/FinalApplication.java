package swishtech.sumitbt;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.authentication.configurers.GlobalAuthenticationConfigurerAdapter;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.builders.WebSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.authority.AuthorityUtils;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import swishtech.sumitbt.repositories.UserRepo;

@SpringBootApplication
public class FinalApplication
{

	public static void main(String[] args)
	{
		SpringApplication.run(FinalApplication.class, args);
	}
}

@Configuration
class WebSecurityConfiguration extends GlobalAuthenticationConfigurerAdapter
{

  @Autowired
  UserRepo userRepo;

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
		  public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException
		  {
			  swishtech.sumitbt.models.User user = userRepo.findByUsername(username);
			  if(user != null)
			  {
				  return new User(user.getUsername(), user.getPassword(), true, true, true, true, AuthorityUtils.createAuthorityList(user.getRole().getRolename()));
			  }
			  else
			  {
				  throw new UsernameNotFoundException("could not find the user '"+ username + "'");
			  }
		  }
      
	  };
  }
}

@EnableWebSecurity
@Configuration
class WebSecurityConfig extends WebSecurityConfigurerAdapter
{
 
	@Override
	public void configure(WebSecurity web) throws Exception
	{
	    web.ignoring()
	    	.antMatchers(HttpMethod.GET,"/book")
	    	.antMatchers(HttpMethod.POST, "/user")
	    	.antMatchers(HttpMethod.POST, "/user/forgotpassword")
	    	.antMatchers(HttpMethod.POST, "/reset/{token}")
	    	.antMatchers(HttpMethod.GET, "/confirm/{token}");
	}
	
  @Override
  protected void configure(HttpSecurity http) throws Exception
  {
    http.authorizeRequests()
    	.anyRequest().fullyAuthenticated()
        .and().httpBasic().and().
    csrf().disable();
  }
}