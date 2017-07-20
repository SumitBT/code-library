package swishtech.api.controllers;

import java.util.Date;
import java.util.UUID;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import swishtech.api.models.EmailVerificationToken;
import swishtech.api.models.User;
import swishtech.api.other.Response;
import swishtech.api.repositories.EmailVerificationTokenRepo;
import swishtech.api.repositories.UserRepo;
import swishtech.api.services.MailService;

@RestController
public class UserControllers
{
	@Autowired
	private UserRepo userRepo;
	
	@Autowired
	private EmailVerificationTokenRepo emailVerificationTokenRepo;
	
	@Autowired
	private MailService ms;
	
	@ResponseBody
	@RequestMapping(value="/user",method=RequestMethod.GET)
	public User details()
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		return user;
	}
	
	@ResponseBody
	@RequestMapping(value="/user",method=RequestMethod.POST)
	public Response signup(@RequestBody User user)
	{
		Response response = new Response();
		try
		{
			if(user.getEmail().equals(null)||user.getEmail().equals(""))
			{
				response.setSuccess(false);
				response.setMessage("Email can't be null!");
				return response;
			}
			else if(userRepo.findByEmail(user.getEmail()) != null)
			{
				response.setSuccess(false);
				response.setMessage("Email already Exists!");
				return response;
			}
			else if(user.getFirstName().equals(null)||user.getFirstName().equals(""))
			{
				response.setSuccess(false);
				response.setMessage("FirstName can't be null!");
				return response;
			}
			else if(user.getLastName().equals(null)||user.getLastName().equals(""))
			{
				response.setSuccess(false);
				response.setMessage("LastName can't be null!");
				return response;
			}
			else if(user.getPassword().equals(null)||user.getPassword().equals(""))
			{
				response.setSuccess(false);
				response.setMessage("Password can't be null!");
				return response;
			}
		}catch(Exception e)
		{
			response.setSuccess(false);
			response.setMessage(e.toString());
			return response;
		}
		user.setRoleId(3);
		user.setStatusId(2);
		user.setSignupDt(new Date());
		User u;
		try
		{
			u = userRepo.save(user);
		}catch(Exception e)
		{
			response.setSuccess(false);
			response.setMessage(e.toString());
			return response;
		}
		EmailVerificationToken evt = new EmailVerificationToken(UUID.randomUUID().toString(), u.getUserId());
		evt.setVerified(false);
		try
		{
			emailVerificationTokenRepo.save(evt);
		}catch(Exception e)
		{
			userRepo.delete(u);
			response.setSuccess(false);
			response.setMessage(e.toString());
			return response;
		}
		try
		{
			ms.sendEmailVerificationMail(u);
		}catch(Exception e)
		{
			emailVerificationTokenRepo.delete(evt);
			userRepo.delete(u);
			response.setSuccess(false);
			response.setMessage(e.toString());
			return response;
		}
		return response;
	}
	
	@ResponseBody
	@RequestMapping(value="/login",method=RequestMethod.GET)
	public Response login()
	{
		Response response = new Response();
		response.setMessage("Login Successful");
		return response;
	}
}
